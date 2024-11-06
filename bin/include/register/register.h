#pragma once
#include <stdint.h>

// Write a single bit from a register
void bit_write(uint32_t reg, uint8_t bit, bool value, uint8_t sub_reg = 0)
{
    if (value)
    {
        (*(uint32_t *)(reg + sub_reg)) |= (1 << bit);
        return;
    }
    (*(uint32_t *)(reg + sub_reg)) &= ~(1 << bit);
}

// Read a single bit from a register
uint8_t bit_read(uint32_t reg, uint8_t bit, uint8_t sub_reg = 0)
{
    return (*(uint32_t *)(reg + sub_reg)) && (1 << bit);
}

// Replace the content of an entire register
void register_write(uint32_t reg, uint32_t value, uint8_t sub_reg = 0)
{   
    (*(uint32_t *)(reg + sub_reg)) = value;
}

// Read the content of an entire register
uint32_t register_read(uint32_t reg, uint8_t sub_reg = 0)
{
    return (*(uint32_t *)(reg + sub_reg));
}
