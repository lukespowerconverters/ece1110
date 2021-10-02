SRC = main.cpp mordor.sv cpath.sv dpath.sv decode.sv memory.sv microcode.sv constants.svh

run: obj_dir/Vmordor
	obj_dir/Vmordor | head

obj_dir/Vmordor: $(SRC)
	verilator -Wall --cc mordor.sv --exe main.cpp
	make -C obj_dir -j -f Vmordor.mk Vmordor

ucode.hex: microcode.uas
	python3 uas-olde.py microcode.uas > ucode.hex

decode.svh: microcode.uas
	python3 uas-olde.py -d microcode.uas > decode.svh

zip:
	zip -r mordor.zip $(SRC) Makefile microcode.uas uas-olde.py

clean:
	rm -rf obj_dir
