"""

Have the function GasStation(strArr) take strArr which will be an an array consisting of the following elements: N which will be the number of gas stations in a circular route and each subsequent element will be the string g:c where g is the amount of gas in gallons at that gas station and c will be the amount of gallons of gas needed to get to the following gas station.

For example strArr may be: ["4","3:1","2:2","1:2","0:1"]. Your goal is to return the index of the starting gas station that will allow you to travel around the whole route once, otherwise return the string impossible. For the example above, there are 4 gas stations, and your program should return the string 1 because starting at station 1 you receive 3 gallons of gas and spend 1 getting to the next station. Then you have 2 gallons + 2 more at the next station and you spend 2 so you have 2 gallons when you get to the 3rd station. You then have 3 but you spend 2 getting to the final station, and at the final station you receive 0 gallons and you spend your final gallon getting to your starting point. Starting at any other gas station would make getting around the route impossible, so the answer is 1. If there are multiple gas stations that are possible to start at, return the smallest index (of the gas station). N will be >= 2.


  Idea: 
  First, determine if the scenario has a solution. 
  A scenario has a solution whenever the sum of all g values is >= to the sum of all c values. (Per the problem nomenclature).

  We can determine this by doing a simple traversal in O(N) where N is the number of stations (as in the problem statement).

  Once we guarantee that there is a solution, we know that we can check the starting station greedily in the provided order according to index
  And just simulate the traveling. 

  Simulation implies keeping a record of the current_gas amount (int), so that we can tell if the car can travel to the next station.
  If at any point, the car cannot travel to the next station... we reset the starting node and the gas count, and just simulate again. 

  Since we first checked that the sum of all g >= sum of all c, we know that the segment where we ran out of fuel can be fixed by taking a longer
  prefix (an earlier starting station in the circle) to have more fuel once we get to that segment.

  We can do this simulation in O(n), simply simulate and restart the point if needed. Once we reach the end of the array, we have stored the earliest
  station index i, such that starting at station i, we can go all the way to the last station (N-1) without running out of gas. 

  This is also the first station where we have accumulated enough gas to solve any problems we found during initial exploration. 
"""

# Formats the stations so that they are easier to manipulate.
# Returns the stations as a list of tuples(gas_in, gas_to_next_station) where each of the tuple values is an int.
# Runtime: O(N)
def get_formatted_stations(strArr):
  stations = []
  for station in strArr[1:]:
    gas_in, gas_to_next = station.split(":")
    stations.append((int(gas_in), int(gas_to_next)))
  return stations


# Checks if scenario has solution per the idea above. 
# Runtime: O(N).
def scenario_has_solution(stations):
  total_gas_in, total_gas_spent = 0, 0
  for station in stations:
    gas_in, gas_spent = station
    total_gas_in += gas_in
    total_gas_spent += gas_spent
  
  return total_gas_in >= total_gas_spent

def GasStation(strArr):
  N = int(strArr[0])
  stations = get_formatted_stations(strArr)
  curr_initial_station_idx = 0 # remember to return this +1
  curr_gas = 0

  if not scenario_has_solution(stations):
    return "impossible"
  
  best_starting_station_idx = 0
  curr_station_idx = 0
  curr_gas = 0

  while curr_station_idx < N: #Runtime: O(N)
    # first, we fuel up
    gas_in, gas_to_next = stations[curr_station_idx]
    curr_gas += gas_in
    # then, we travel to the next station
    curr_gas -= gas_to_next
    curr_station_idx += 1
    # check if we need to reset the starting point
    if curr_gas < 0: 
      curr_gas = 0
      curr_initial_station_idx = curr_station_idx ## We will try from scratch starting at the next station.
  
  return curr_initial_station_idx + 1
  

# keep this function call here 
print(GasStation(input()))