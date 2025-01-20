idf_component_register(SRCS "main.cpp"
                       REQUIRES agisostack driver hal
                       PRIV_REQUIRES spi_flash
                       INCLUDE_DIRS "")
