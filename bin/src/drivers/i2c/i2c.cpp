#include "i2c.hpp"

I2C_7::I2C_7()
{
    registers = new I2C0_PER(); // Try to connect to peripheral 0

    if (!registers)
    {
        registers = new I2C1_PER(); // Try to connect to peripheral 1

        if (!registers)
        {
            delete this; // No available I2C peripheral
        }
    }

    cmd_default = (uint8_t *)registers->I2C_COMD0_REG;
    cmd_head = cmd_default;
    cmd_tail = cmd_default;
}

I2C_7::~I2C_7()
{

}

void I2C_7::cmd_tail_update()
{
    while (cmd_tail != cmd_head)
    {
        if (cmd_tail > (cmd_default + 15*4))
        {
            cmd_tail = cmd_default;
        }

        if (bit_read((uint32_t)cmd_tail, 31))
        {
            bit_write((uint32_t)cmd_tail, 31, false);
            cmd_tail += 4;
        }
    }
}

bool I2C_7::communicate(uint8_t *send_bytes, uint8_t send_len,
                        uint8_t *recv_bytes, uint8_t recv_len)
{
    // 

}