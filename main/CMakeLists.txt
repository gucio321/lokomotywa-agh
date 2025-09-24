idf_component_register(SRCS "LokomotywaAGH_main.c"
        "utils.ino"
                            "setup.ino"
                    INCLUDE_DIRS ".")
            #PRIV_REQUIRES esp_wifi nvs_flash esp_driver_ledc

