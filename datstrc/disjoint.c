/*
Problem: Minimum Bus
In a small island, we have a bus transportation networks for inter-city transport.
In this island, each city only has one bus stop.
Not all cities are connected with bus road and sometimes we have to take another transportation type
(like train or taxi) to reach our city destination.
A city without any bus road connecting to other city still need a bus in case of emergency
for intra-city transport.
To facilitate the bus transportation network in that island, we have to calculate the minimum
number of bus to maintain by looking at the connecting bus roads.

Input:
C R (C is the number of city/bus stop, R is the total number of the roads available through the island)
a b (a and b are the city id which have a road connecting them)
The program will ask R number of a b pairs.

Output:
The minimum number of bus we have to procure/maintain through the island.
**********************************************************************************************************************
Example 1
Input:
5 6
0 1
4 3
2 3
2 1
4 1
3 1

Output: 1

Explanation:
There are 5 cities with 6 roads.
Minimum 1 bus needed because all cities are connected by the bus road.
**********************************************************************************************************************
Example 2
Input:
10 7
1 3
4 5
0 2
7 8
0 1
5 6
1 2

Output: 4

Explanation:
There are 10 cities with 7 roads. Minimum 4 buses are needed.
The first bus is for cities 0, 1, 2, 3;
second bus is for cities 4, 5, 6;
third bus is for cities 7 and 8;
fourth bus is only for city 9 (there are 10 cities and city 9 doesnt have any bus road connecting to other cities)
**********************************************************************************************************************
Example 3
Input:
4 2
3 2
0 1

Output: 2

Explanation:
There are 4 cities with 2 roads. Minimum 2 buses are needed.
The first bus is for cities 2 and 3;
second bus is for cities 0 and 1.
*/