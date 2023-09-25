if (NOT TARGET pwm_tone)
    add_library(pwm_tone INTERFACE)

    target_sources(pwm_tone INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/pwm-tone.c
    )

    target_include_directories(pwm_tone INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}
    )

    target_link_libraries(pwm_tone INTERFACE
        pico_stdlib
        hardware_pwm
    )
endif()