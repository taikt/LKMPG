#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/spi/spi.h>

static int spi_probe(struct spi_device *spi)
{
    int ret;

    printk("spi example probe\n");

    spi->bits_per_word = 8;
    spi->mode = SPI_MODE_0;
    ret = spi_setup(spi);
    if (ret < 0)
        return ret;

    printk("spi device name = %s \n", spi->modalias);
    printk("spi device freq = %d \n", spi->max_speed_hz);
    printk("spi device's bus_num = %d \n", spi->master->bus_num);
    printk("spi device cs  = %d \n", spi->chip_select);
    printk("spi device mode = %d \n\n", spi->mode);

    return 0;
}

static int spi_remove(struct spi_device *spi)
{
    printk("spi example remove\n");

    /* Your spi remove code */

    return 0;
}

static struct spi_driver my_spi_driver = {
    .driver = {
        .name = "my_spi",
    },
    .probe = spi_probe,
    .remove = spi_remove,
};

module_spi_driver(my_spi_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bob Mottram");
MODULE_DESCRIPTION("SPI driver module example");
