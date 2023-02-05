macro(get_sources SOURCE_LIST DIR)
    set(FOLDER_NAMES main gui domain) #names of folders
    add_sources(${SOURCE_LIST} "${DIR}/sources" "${FOLDER_NAMES}")
endmacro()