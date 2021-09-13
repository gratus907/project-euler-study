src_dir = ./src
lib_dir = ./lib
res_dir = ./results
FLAGS = -Ofast
CPP = g++-11

help:
	echo $(prj_src)

run:
	echo "Compile and run $(id)"
	$(CPP) $(src_dir)/pe_$(id).cpp -o $(src_dir)/pe_$(id).out $(FLAGS)
	$(src_dir)/pe_$(id).out > $(res_dir)/pe_$(id).txt
