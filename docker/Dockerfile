FROM ubuntu:22.04

RUN <<EOF
apt update -y 
apt upgrade -y
apt install -y \
	gcc \
	valgrind \
	git \
	libreadline-dev \
	cmake \
	g++ 
git clone https://github.com/google/googletest.git
cd googletest
mkdir build
cd build
cmake ..
make 
cp -r ../googlemock/include/gmock /usr/local/include/gmock 
cp -r ../googletest/include/gtest /usr/local/include/gtest
cp lib/*.a /usr/local/lib/
EOF

RUN adduser \
	--disabled-password \
	--gecos "" \
	minishell

USER minishell
WORKDIR /home/minishell

CMD ["/bin/bash"]