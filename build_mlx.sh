git clone https://github.com/codam-coding-college/MLX42.git
cd MLX42
cmake -B build # build here refers to the outputfolder.
cmake --build build -j4 # or do make -C build -j4

sudo apt update
sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev