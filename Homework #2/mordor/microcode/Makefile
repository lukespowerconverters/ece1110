run: obj_dir/Vmordor
	obj_dir/Vmordor | head

obj_dir/Vmordor: mordor.sv main.cpp ucode.hex decode.svh cpath.sv dpath.sv decode.sv memory.sv
	verilator -Wall --cc mordor.sv --exe main.cpp
	make -C obj_dir -j -f Vmordor.mk Vmordor

ucode.hex: microcode.uas
	python3.10 uas.py microcode.uas > ucode.hex

decode.svh: microcode.uas
	python3.10 uas.py -d microcode.uas > decode.svh

clean:
	rm -rf obj_dir
