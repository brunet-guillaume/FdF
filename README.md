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
<table>
<tr><td>The horizontal position corresponds to its axis</td></tr>
<tr><td>The vertical position corresponds to its ordinate</td></tr>
<tr><td>The value corresponds to its altitude</td></tr>
</table>

## Bonus part

In the bonus part, we need to :
<table>
<tr><td>Include one extra projection</td></tr>
<tr><td>Add possibility to zoom in and out</td></tr>
<tr><td>Add the possibility to translate the model</td></tr>
<tr><td>Add the possibility to rotate the model</td></tr>
<tr><td>Add one more bonus of our choice</td></tr>
</table>

### Compilation
```bash
git clone git@gitlab.com:uotiug42/graphic-projects/fdf.git
cd fdf
# mandatory part :
make
# bonus part :
make bonus
```
