# PBRT-v4 Extended 

This repository contains the source code for the rendering system, PBRT-v4 extended. It extends the original rendering system, PBRT-v4 to include: 

* Bilateral filtering 
* Procedural Content Generation (PCG)

The PBRT-v4 source code is available at [git respository](https://github.com/mmp/pbrt-v4). 

The source code for bilaterial filtering can be found at 
## TODO RAJ

The source code for PCG can be found in `pbrt-v4/src/pbrt/pcgUtil`. The new classes we implemented are: 

* procedural
* pcg_sampling 
* pbrt_exporter 
* sampleTo3D 

`pbrt-v4/src/pbrt/util/transformer.cpp` was updated for PCG. 

## TODO RILEY 

`pbrt-v4/src/pbrt/cmd/pbrt.cpp` is modified with our implementation from Lines 288-351. 



## Building the code 

PBRT uses `cmake`, to compile the code run the following commands. 

```
$ mkdir build 
$ cd build
$ cmake ..
$ make -j 
```

## Running the code 

To render our 3D scene, run the following command.

```
$ ./pbrt ../epic_model/scene-v4.pbrt
```

Inside the `build` folder, a `scene.png` file should be generated.

#### Bilateral Filtering 

To test rendering the scene with/without bilateral filtering, you need update `pbrt-v4/epic_model/scene-v4.pbrt` file. Set the `bilateral` parameter to `true` or `false`. 

You can also edit the `bilateral_sigma_spatial` and `bilateral_sigma_range` parameters...

## TODO RAJ 

Here is an example. 

```
Film "rgb"
    "string filename" [ "scene.png" ]
    "integer yresolution" [ 396 ] 
    "integer xresolution" [ 960 ]
    "bool bilateral" [ false ]
    "float bilateral_sigma_spatial" [ 1 ]
    "float bilateral_sigma_range" [ 0.2 ]
```


#### Procedural Content Generation

To test PCG, you need to run the following command: 

## TODO RAJ 


