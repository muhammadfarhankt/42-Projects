def ft_water_reminder():
    days = int(input('Days since last watering: '))
    if days >= 3:
        print('Water the plants!')
    else:
        print('Plants are fine')
