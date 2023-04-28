rm ./generate -rf
mkdir ./generate

cp ./src/mapping/be_cb_module.c ./src/be_cb_module.c

tools/coc/coc -o generate default src -c default/berry_conf.h

rm ./src/be_cb_module.c