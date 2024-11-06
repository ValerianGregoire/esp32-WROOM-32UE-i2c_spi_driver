#pragma once

#include <stdint.h>
class I2C_PER{
public:
    const uint32_t I2C_SLAVE_ADDR_REG{0};
    const uint32_t I2C_RXFIFO_ST_REG{0};
    const uint32_t I2C_FIFO_CONF_REG{0};
    const uint32_t I2C_SDA_HOLD_REG{0};
    const uint32_t I2C_SDA_SAMPLE_REG{0};
    const uint32_t I2C_SCL_LOW_PERIOD_REG{0};
    const uint32_t I2C_SCL_HIGH_PERIOD_REG{0};
    const uint32_t I2C_SCL_START_HOLD_REG{0};
    const uint32_t I2C_SCL_RSTART_SETUP_REG{0};
    const uint32_t I2C_SCL_STOP_HOLD_REG{0};
    const uint32_t I2C_SCL_STOP_SETUP_REG{0};
    const uint32_t I2C_SCL_FILTER_CFG_REG{0};
    const uint32_t I2C_SDA_FILTER_CFG_REG{0};
    const uint32_t I2C_INT_RAW_REG{0};
    const uint32_t I2C_INT_CLR_REG{0};
    const uint32_t I2C_INT_ENA_REG{0};
    const uint32_t I2C_INT_STATUS_REG{0};
    const uint32_t I2C_COMD0_REG{0};
    static bool in_use;      // Prevents the use of the same peripheral twice
    virtual void init() = 0;

    I2C_PER(){}
};

class I2C0_PER: public I2C_PER{
public:
    const uint32_t I2C_SLAVE_ADDR_REG{ 0x3FF53010 };
    const uint32_t I2C_RXFIFO_ST_REG{ 0x3FF53014 };
    const uint32_t I2C_FIFO_CONF_REG{ 0x3FF53018 };
    const uint32_t I2C_SDA_HOLD_REG{ 0x3FF53030 };
    const uint32_t I2C_SDA_SAMPLE_REG{ 0x3FF53034 };
    const uint32_t I2C_SCL_LOW_PERIOD_REG{ 0x3FF53000 };
    const uint32_t I2C_SCL_HIGH_PERIOD_REG{ 0x3FF53038 };
    const uint32_t I2C_SCL_START_HOLD_REG{ 0x3FF53040 };
    const uint32_t I2C_SCL_RSTART_SETUP_REG{ 0x3FF53044 };
    const uint32_t I2C_SCL_STOP_HOLD_REG{ 0x3FF53048 };
    const uint32_t I2C_SCL_STOP_SETUP_REG{ 0x3FF5304C };
    const uint32_t I2C_SCL_FILTER_CFG_REG{ 0x3FF53050 };
    const uint32_t I2C_SDA_FILTER_CFG_REG{ 0x3FF53054 };
    const uint32_t I2C_INT_RAW_REG{ 0x3FF53020 };
    const uint32_t I2C_INT_CLR_REG{ 0x3FF53024 };
    const uint32_t I2C_INT_ENA_REG{ 0x3FF53028 };
    const uint32_t I2C_INT_STATUS_REG{ 0x3FF5302C };
    const uint32_t I2C_COMD0_REG{ 0x3FF53058 };

    static bool in_use; // Prevents the use of the same peripheral twice

    I2C0_PER()
    {
        if (!I2C0_PER::in_use)
        {
            I2C0_PER::in_use = true;
            return;
        }
        delete this;
    }

    ~I2C0_PER() { I2C0_PER::in_use = false; }

private:
    void init() override {}
};

class I2C1_PER: public I2C_PER
{
public:
    const uint32_t I2C_SLAVE_ADDR_REG{0x3FF53010};
    const uint32_t I2C_RXFIFO_ST_REG{0x3FF53014};
    const uint32_t I2C_FIFO_CONF_REG{0x3FF53018};
    const uint32_t I2C_SDA_HOLD_REG{0x3FF53030};
    const uint32_t I2C_SDA_SAMPLE_REG{0x3FF53034};
    const uint32_t I2C_SCL_LOW_PERIOD_REG{0x3FF53000};
    const uint32_t I2C_SCL_HIGH_PERIOD_REG{0x3FF53038};
    const uint32_t I2C_SCL_START_HOLD_REG{0x3FF53040};
    const uint32_t I2C_SCL_RSTART_SETUP_REG{0x3FF53044};
    const uint32_t I2C_SCL_STOP_HOLD_REG{0x3FF53048};
    const uint32_t I2C_SCL_STOP_SETUP_REG{0x3FF5304C};
    const uint32_t I2C_SCL_FILTER_CFG_REG{0x3FF53050};
    const uint32_t I2C_SDA_FILTER_CFG_REG{0x3FF53054};
    const uint32_t I2C_INT_RAW_REG{0x3FF53020};
    const uint32_t I2C_INT_CLR_REG{0x3FF53024};
    const uint32_t I2C_INT_ENA_REG{0x3FF53028};
    const uint32_t I2C_INT_STATUS_REG{0x3FF5302C};
    const uint32_t I2C_COMD0_REG{0x3FF53058};

    static bool in_use; // Prevents the use of the same peripheral twice

    I2C1_PER()
    {
        if (!I2C1_PER::in_use)
        {
            I2C1_PER::in_use = true;
            return;
        }
        delete this;
    }

    ~I2C1_PER() { I2C1_PER::in_use = false; }

private:
    void init() override {}
};