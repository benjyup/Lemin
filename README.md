# Lemin
The objective of your program is to find the quickest way to make the ants cross over the anthill. To do so, each single ant need to take the shortest route (and not necessarily the easiest), whithout walking on its peers, and avoiding traffic jams.

At the beginning of the game, all of the ants are in the anthill entrance.
The goal is to lead them to the exit room, in a minimum amount of laps.
Each room could contain a single ant at a time (except ##start and ##end, which can contain as many as needed).
With each lap, you can move each ant only once by following a tunnel (if the receiving room is clear).

You must show the result on the standard output, in this order: number_of_ants, rooms, tunnels and then for each
lap, a series of
P n
−
r
where
n
is the number of the ant, and
r
the name of the room it gets into.
In the output, you must display a comment indicating the part that will follow. These comment must be exactly like
in the examples.
