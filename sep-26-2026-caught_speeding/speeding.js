const speeds = [55, 75, 82, 68, 57, 95, 115, 118, 60];
const limit = 80;

function caught_speeding(speeds, limit) {
  let overSpeeding_count = 0;
  let total_speed_over_speedLimit = 0;

  for (let speed of speeds) {
    if (speed > limit) {
      overSpeeding_count++;
      total_speed_over_speedLimit += speed - limit;
    }
  }

  if (overSpeeding_count == 0) {
    return [0, 0];
  }

  let average_speed_over_speedLimit =
    total_speed_over_speedLimit / overSpeeding_count;

  return [overSpeeding_count, average_speed_over_speedLimit];
}

let result = caught_speeding(speeds, limit);

console.log(result);
