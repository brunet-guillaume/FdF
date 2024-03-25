# FdF (42 school)
> 📑 &ensp;Subject [here](/subject/subject_FdF.pdf) <br />
✅ &ensp;**125**/100

Project in the second circle in 42 school.

## Mandatory part

The idea here, is to display a wireframe model representation of a 3D landscape using the MiniLibX ([git repo](https://github.com/42Paris/minilibx-linux)).

The program has to represent the model in isometric projection.

Here is an example of a map file :
```bash
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```
Each number represents a point in space :
1) The horizontal position corresponds to its axis
2) The vertical position corresponds to its ordinate
3) The value corresponds to its altitude

## Bonus part

In the bonus part, we need to :
1) Include one extra projection
2) Add possibility to zoom in and out
3) Add the possibility to translate the model
4) Add the possibility to rotate the model
5) Add one more bonus of our choice


### Compilation
```bash
git clone https://gitlab.com/uotiug42/fdf.git
cd fdf
# mandatory part :
make
# bonus part :
make bonus
```
