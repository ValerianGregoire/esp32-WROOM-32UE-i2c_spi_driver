#pragma once
#include <stdint.h>
#include "../../../include/register/register.h"
#include "i2c_registers.h"

#define READ_BUFFER_SIZE 32
#define READ_BUFFER_LEN 8

// Comment this line out to toggle standard mode
#define I2C_FAST_MODE 1


// Support for I2C with 7 bit addressing
class I2C_7 {
public:
    I2C_7();
    ~I2C_7();

    void init();

    bool check();

    /* Communication process
    * A start condition cmd is placed in cmd0
    * cmd_head progresses forward as cmds are placed
    * After reaching the limit of cmds, cmd_head returns to default
    * Before reaching cmd_tail, cmd_head calls cmd_tail_update
    * cmd_tail checks if the current cmd register is done with the cmd
    * if so, cmd tail goes to the next, until finding an unfinished cmd
    * or reaching cmd_head and stopping on it without checking the cmd
    * cmd_head resumes its cmd writing until the end
    * cmd_head writes a stop condition once everything is done
    */
    bool communicate(uint8_t *send_bytes, uint8_t send_len,
                        uint8_t *recv_bytes, uint8_t recv_len);

private:
    bool master; // Master or slave mode

    I2C_PER *registers;

    uint8_t sda_pin;
    uint8_t scl_pin;

    uint8_t read_buffer[READ_BUFFER_SIZE];
    uint8_t *read_head; // Next byte to write in the buffer
    uint8_t *read_tail; // Next byte to read from the buffer

    uint8_t *cmd_head;
    uint8_t *cmd_tail;
    uint8_t *cmd_default;
    void cmd_tail_update();
};