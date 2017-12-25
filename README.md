hpxcl
====

HPX is an open-source, general purpose C++ library for developing parallel and distributed applications with a broad community usage. This repository is for the development of HPX Compute language (HPXCL) API for the integration of GPU computation with asynchronous many task execution library HPX. Asynchronous functions are provided for kernel launch, kernel execution and data transfer with the capability to hide the communication latency through computation. This is done through the provision of Buffer, Device and Program.

To give an example, computation on multiple CPU nodes, GPU nodes can all occur in parallel and can be synchronized when the results are required by the user through the use of futures. This system unleashes the potential to take computation to the exa-scale level.

The [documentation](http://stellar-group.github.io/hpxcl/docs/html/index.html) of the nightly build is available.

In any case, if you happen to run into problems we very much encourage and appreciate
any [issue](http://github.com/STEllAR-GROUP/hpxcl/issues) reports through the issue tracker for this Github project.

The [CircleCI](https://circleci.com/gh/STEllAR-GROUP/hpxcl) contiguous
integration service tracks the current build status for the master branch:
![HPXCL master branch build status](https://circleci.com/gh/STEllAR-GROUP/hpxcl/tree/master.svg?style=svg "")

Build
===

- CMake >= 3.0
- GCC >= 4.9 
- HPX (Please use the current version in the master branch)

CUDA
==

Prerequisites:

- CUDA SDK >= 7.0

Building:
```
mkdir build && cd build
cmake \
-DHPX_ROOT=/home/ubuntu/opt/hpx/ \
-DHPXCL_WITH_CUDA=ON \
-DCUDA_TOOLKIT_ROOT_DIR=/opt/packages/cuda-7.0/	\
..
```

OpenCl
==

Prerequisties:

- OpenCl >= 1.1

Building:
```
mkdir build && cd build
cmake	\
-DHPX_ROOT=/home/ubuntu/opt/hpx	\
-DHPXCL_WITH_OPENCL=ON \
..
```


Options
==

- Build CUDA support: -HPXCL_WITH_CUDA (Default=Off)
- Build examples: -DHPXCL_BUILD_EXAMPLES (Default=On)
- Build benchmark: -DHPXCL_WITH_BENCHMARK (Default=Off)
- Build documentation: -DHPX_WITH_DOCUMENTATION (Defaut=Off)
- Build the naive CUDA benchmarks: -DHPXCL_WITH_NAIVE_CUDA_BENCHMARK (DEFAULT=Off)
- Build the HPXCL CUDA Version with Streams: -DHPXCL_CUDA_WITH_STREAM (Default=On)
