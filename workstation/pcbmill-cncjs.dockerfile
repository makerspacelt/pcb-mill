FROM cncjs/cncjs
RUN apt-get update && apt-get install git -y --no-install-recommends
RUN git clone https://github.com/kreso-t/cncjs-kt-ext.git
RUN cd cncjs-kt-ext
RUN npm install
WORKDIR /opt/cncjs/cncjs-kt-ext
# 