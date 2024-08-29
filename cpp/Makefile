# flags
WIN32=true

# Windows
ifdef WIN32
create-build:
	mkdir build

run-cmake:
	cd /D build && cmake ../ -G "MinGW Makefiles" -Wdev

clean-build:
	rd /S /Q build

# Linux
else
create-build:
	mkdir build

run-cmake:
	cd build && cmake ../ -G "Unix Makefiles" -Wdev

clean-build:
	rm -rf build

endif

# make commands
rebuild:
	$(MAKE) clean-build
	$(MAKE) create-build
	$(MAKE) run-cmake