gcc -O3 -march=native -mtune=native -ffast-math -DTIME matmul.c -o orig -lm
gcc -O3 -march=native -mtune=native -ffast-math -DTIME matmul.naive.tiled.1d.c -o tiled.naive.1d.tiled -lm
gcc -O3 -march=native -mtune=native -ffast-math -DTIME matmul.naive.tiled.1d.permute.c -o tiled.naive.1d.tiled.permute -lm
gcc -O3 -march=native -mtune=native -ffast-math -DTIME matmul.naive.tiled.2d.c -o tiled.naive.2d.tiled -lm
gcc -O3 -march=native -mtune=native -ffast-math -DTIME matmul.naive.tiled.2d.permute.c -o tiled.naive.2d.tiled.permute -lm
gcc -O3 -march=native -mtune=native -ffast-math -DTIME matmul.naive.tiled.3d.permute.c -o tiled.naive.3d.tiled.permute -lm
gcc -O3 -march=native -mtune=native -ffast-math -DTIME -fopenmp matmul.naive.tiled.3d.permute.vectorize.c -o tiled.naive.3d.tiled.permute.vectorize -lm
gcc -O3 -march=native -mtune=native -ffast-math -DTIME -fopenmp matmul.naive.tiled.3d.permute.vectorize.par.c -o tiled.naive.3d.tiled.permute.vectorize.par -lm
gcc -O3 -march=native -mtune=native -ffast-math -DTIME matmul.tiled.c -o tiled.pluto -lm
gcc -O3 -march=native -mtune=native -ffast-math -DTIME -fopenmp matmul.par.c -o tiled.par.pluto  -lm

