/*

MASTER OR SLAVE MODE - SELECT WITH I2C_MS_MODE REGISTER



The I2C controller contains the following units:
• RAM, the size of which is 32 x 8 bits, and it is directly mapped onto the address space of the CPU cores,
starting at address REG_I2C_BASE+0x100. Each byte of I2C data is stored in a 32-bit word of memory (so,
the first byte is at +0x100, the second byte at +0x104, the third byte at +0x108, etc.) Users need to set
register I2C_NONFIFO_EN.

• A CMD_Controller and 16 command registers (cmd0 ~ cmd15), which are used by the I2C Master to control
data transmission. One command at a time is executed by the I2C controller.

• SCL_FSM: A state machine that controls the SCL clock. The I2C_SCL_HIGH_PERIOD_REG and I2C_SCL_
LOW_PERIOD_REG registers are used to configure the frequency and duty cycle of the signal on the SCL
line.

• SDA_FSM: A state machine that controls the SDA data line.

• DATA_Shifter which converts the byte data to an outgoing bitstream, or converts an incoming bitstream to
byte data. I2C_RX_LSB_FIRST and I2C_TX_LSB_FIRST can be used for configuring whether the LSB or
MSB is stored or transmitted first.

• SCL_Filter and SDA_Filter: Input noise filter for the I2C_Slave. The filter can be enabled or disabled by
configuring I2C_SCL_FILTER_EN and I2C_SDA_FILTER_EN. The filter can remove line glitches with pulse
width less than I2C_SCL_FILTER_THRES and I2C_SDA_FILTER_THRES ABP clock cycles.


*/