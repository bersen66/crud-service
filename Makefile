run-release:
	@mkdir -p build-release
	@cd build-release && \
		cmake  -DCMAKE_BUILD_TYPE=Release -DUSERVER_NO_WERROR=ON -DUSERVER_DOWNLOAD_PACKAGES=ON -DUSERVER_LTO=OFF ..  &&\
		cmake --build . && \
		cp '../configs'/* . && \
		./datamart
