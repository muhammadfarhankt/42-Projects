*This project has been created as part of the 42 curriculum by mfarhan.*

---

## Description

**Born2beRoot** is a system administration project from the 42 curriculum focused on understanding Linux server fundamentals, security concepts, and service management inside a virtualized environment.

The project consists of installing and configuring a Debian-based operating system on a virtual machine, followed by progressive system hardening through user management, access control, network security, automation, and monitoring.

Although the subject does not strictly require a production-grade server, the system is intentionally designed to be **minimal and secure** in order to reduce the attack surface, improve stability, and ensure that every configuration choice is deliberate and justifiable.  
The bonus part extends this base system by deploying real-world services to demonstrate how a properly configured server can safely host applications.

---

## Objectives

- Understand how virtual machines work and why they are used
- Learn Debian-based Linux installation and configuration
- Apply security best practices and the principle of least privilege
- Configure users, groups, permissions, and sudo rules
- Secure remote access and network traffic
- Automate system monitoring using Bash and cron
- Deploy lightweight web services in a controlled environment

---

## Environment & Tools

- **Virtualization:** VirtualBox  
- **Operating System:** Debian (stable)  
- **Shell:** Bash  
- **Firewall:** UFW  
- **Remote Access:** SSH  
- **Mandatory SSH Port:** `4242`  
- **Web Root (Bonus):** `/var/www/html`

### Virtual Machine Overview

The system runs inside a **virtual machine**, which is a software-based emulation of a physical computer.  
Virtualization allows isolation, reproducibility, and safe experimentation without impacting the host system, making it ideal for learning system administration and security concepts.

---

## Disk & Partitioning Layout

The system uses **encrypted Logical Volume Management (LVM)** to ensure flexibility, security, and proper isolation between system components.

- **/boot:** 500 MB (unencrypted, required for bootloader)
- **Disk Encryption:** LUKS
- **Encryption Password:** `Encrypt@42`
- **Volume Group Name:** `LVMGroup`

### Logical Volumes

| Mount Point | Size   |
|------------|--------|
| `/` (root) | 10 GB  |
| `swap`     | 2.3 GB |
| `/home`    | 5 GB   |
| `/var`     | 3 GB   |
| `/srv`     | 3 GB   |
| `/tmp`     | 3 GB   |
| `/var/log` | 4 GB   |

This layout isolates frequently written directories such as `/var`, `/var/log`, and `/tmp`, limiting the impact of disk saturation and improving system reliability.

---

## Mandatory Implementation Summary

### Operating System Choice

**Debian (stable)** was chosen for its reliability, conservative update policy, extensive documentation, and strong community support.  
Compared to CentOS, Debian prioritizes long-term stability through thoroughly tested packages rather than enterprise lifecycle coupling.

### Package Management & Security Framework

- **APT** is used for package management due to its simplicity and scripting support.
- Debian uses **AppArmor**, a mandatory access control system that restricts program capabilities using profiles, improving security with minimal configuration overhead.

---

### Users & Groups

- Root account secured and not used for daily operations
- Primary user: `mfarhan`
- Groups: `sudo`, `user42`
- Root SSH login disabled

This enforces proper privilege separation and limits potential damage from compromised accounts.

---

### Password Policy (PAM)

A strong password policy is enforced to protect against brute-force attacks and credential reuse:

- Password expiration every 30 days
- Minimum length of 10 characters
- Uppercase, lowercase, digit, and special character required
- Username not allowed in password

While strong policies can reduce convenience, they significantly improve system security when balanced correctly.

---

### Sudo Configuration

`sudo` enables controlled privilege escalation without sharing the root password.

Configured rules include:
- Maximum 3 authentication attempts
- TTY required
- Restricted executable paths
- All sudo actions logged to `/var/log/sudo/`

This improves accountability and traceability of administrative actions.

---

### SSH (Secure Shell)

SSH provides encrypted remote access to the system.

- Service running on port `4242`
- Root login disabled
- Access restricted to authorized users

SSH allows secure system administration without physical access to the machine.

---

### Firewall (UFW)

**UFW (Uncomplicated Firewall)** is used to manage network access.

- Enabled by default
- Only required ports allowed
- Blocks unauthorized inbound connections

UFW provides a simple yet effective firewall layer.

---

### Monitoring & Automation

A custom Bash script (`monitoring.sh`) collects system metrics and broadcasts them using `wall`.

The script runs:
- At system startup
- Every 10 minutes via `cron`

#### Reported Metrics

- OS and kernel version
- CPU count and load
- RAM and disk usage
- Last reboot time
- LVM status
- Active TCP connections
- Logged-in users
- Network IP and MAC addresses
- Number of executed sudo commands

`cron` is used to automate recurring tasks without manual intervention.

---

## Bonus Implementation

The bonus section demonstrates how additional services can be securely deployed on top of the base system.

### WordPress Stack

A lightweight and efficient web stack was selected:

- **Web Server:** Lighttpd  
- **Database:** MariaDB  
- **Backend:** PHP (FastCGI)  

This setup minimizes resource usage while remaining fully functional.  
WordPress is served from `/var/www/html`.

### Additional Service

- **OpenLiteSpeed** installed and running (`lsws.service`)
- Chosen as a high-performance, event-driven web server
- Installed for demonstration and justification purposes (not used by WordPress)

---

## Security Summary

- No graphical interface installed
- Encrypted disk using LVM
- AppArmor enabled
- Minimal open ports
- Secure SSH configuration
- Strong authentication and sudo rules
- Principle of least privilege applied throughout the system

---

## Instructions

### System Access

```bash
ssh mfarhan@localhost -p 4242