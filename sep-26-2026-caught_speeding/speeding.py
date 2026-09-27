
speeds = [55, 75, 82, 68, 57, 95, 115, 118, 60]
limit = 80

def caught_speeding(speeds, limit):
    overSpeeding_count = 0
    total_speed_over_speedLimit = 0

    for speed in speeds:
        if speed > limit:
            overSpeeding_count += 1
            total_speed_over_speedLimit += (speed - limit)


    average_speed_over_speedLimit = total_speed_over_speedLimit / overSpeeding_count

    return [overSpeeding_count, average_speed_over_speedLimit] 


result = caught_speeding(speeds, limit)

print(result)