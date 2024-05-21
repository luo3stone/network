#include <stdio.h>
#include <unistd.h>
#include "network.h"

int NetworkOper(char* oper_type, void* in, void* out, char* res, int res_size){
    return 0;
}

int main(int argc, char** argv) {
    NetworkOperFunc func = {
        .algorithm_enable_cb = NetworkOper,
        .dev_ctrl_cb = NetworkOper,
        .get_config_cb = NetworkOper,
        .set_config_cb = NetworkOper,
        .upgrade_cb = NetworkOper
    };

    NetworkInit(&func);

    sleep(10);

    char* boby = "{\"name\":\"test\"}";
    char resp[512] = {0};
    NetworkRequest("http://192.168.100.6:8080/post_test", "unused", boby, resp, sizeof(resp), 1000 * 10);
    printf("%s\n", resp);

    while (1) {
        sleep(1);
    }

}