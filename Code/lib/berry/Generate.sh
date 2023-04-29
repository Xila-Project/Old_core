rm ./generate -rf
mkdir ./generate

cp ../berry_mapping/src/be_cb_module.c ./src/be_cb_module.c
cp ../Xila/src/Software/Berry/Interpreter/Modules/test.cpp ./src/test.cpp


tools/coc/coc -o generate default src -c default/berry_conf.h

rm ./src/be_cb_module.c
rm ./src/test.cpp