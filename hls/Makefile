SOURCE_PATH 		:= 	$(CURDIR)/../source
TOPPRA_OBJ_PATH 	:=	$(SOURCE_PATH)/build/src/CMakeFiles/toppra.dir/toppra
TOPPRA_OBJECTS 		+= 	$(TOPPRA_OBJ_PATH)/constraint.cpp.o
TOPPRA_OBJECTS 		+= 	$(TOPPRA_OBJ_PATH)/constraint/linear_joint_velocity.cpp.o
TOPPRA_OBJECTS 		+= 	$(TOPPRA_OBJ_PATH)/constraint/linear_joint_acceleration.cpp.o
TOPPRA_OBJECTS 		+= 	$(TOPPRA_OBJ_PATH)/constraint/joint_torque.cpp.o
TOPPRA_OBJECTS 		+= 	$(TOPPRA_OBJ_PATH)/constraint/cartesian_velocity_norm.cpp.o
TOPPRA_OBJECTS 		+= 	$(TOPPRA_OBJ_PATH)/solver.cpp.o
TOPPRA_OBJECTS 		+= 	$(TOPPRA_OBJ_PATH)/solver/seidel.cpp.o
TOPPRA_OBJECTS 		+= 	$(TOPPRA_OBJ_PATH)/solver/seidel-parallel.cpp.o
TOPPRA_OBJECTS 		+= 	$(TOPPRA_OBJ_PATH)/geometric_path.cpp.o
TOPPRA_OBJECTS 		+= 	$(TOPPRA_OBJ_PATH)/geometric_path/piecewise_poly_path.cpp.o
TOPPRA_OBJECTS 		+= 	$(TOPPRA_OBJ_PATH)/parametrizer/const_accel.cpp.o
TOPPRA_OBJECTS 		+= 	$(TOPPRA_OBJ_PATH)/parametrizer.cpp.o
TOPPRA_OBJECTS 		+= 	$(TOPPRA_OBJ_PATH)/algorithm.cpp.o
TOPPRA_OBJECTS 		+= 	$(TOPPRA_OBJ_PATH)/algorithm/toppra.cpp.o
# TOPPRA_OBJECTS 		+= 	$(TOPPRA_OBJ_PATH)/solver/qpOASES-wrapper.cpp.o

all: build

build: 
	mkdir -p lib
	g++ -shared -o lib/libtopprah.so $(TOPPRA_OBJECTS)
	cp $(SOURCE_PATH)/build/lib/libgtest.a lib/
clean:
	rm -rf lib/

