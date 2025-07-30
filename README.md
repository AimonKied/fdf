# FDF - Fil de Fer (42 Project)

**FDF** is a graphical project from the 42 curriculum. The goal is to build a simple 3D wireframe renderer that projects a 3D terrain (based on height maps) into a 2D isometric view. It is written in C and uses the **MiniLibX** graphics library provided by 42.

The program reads `.fdf` files, which contain height values (Z-axis) for each point on a grid, and displays them as a connected wireframe model in a window.

Example:

`0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0`  
`0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0`  
`0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0`  
`0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0`  
`0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0`  
`0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0`  
`0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0`  
`0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0`  
`0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0`  
`0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0`  
`0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0`  

 Output:
 
<img src="images/fdf_42.png" alt="FDF Demo" height="400" width="500"/>


---

### Requirements

- `gcc` compiler
- `make`
- MiniLibX (the one in the repo is for macOS)
- A Unix-based system (macOS or Linux)

### Compilation

```bash
make
./fdf <infile.fdf>
