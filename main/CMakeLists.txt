idf_component_register(SRCS "main.cpp"
                       REQUIRES iso-on-esp driver hal
                       PRIV_REQUIRES spi_flash
                       INCLUDE_DIRS "")
