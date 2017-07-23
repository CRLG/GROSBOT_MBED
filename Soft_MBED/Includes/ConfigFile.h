/**
 * Configuration file interface class (Version 0.0.1)
 *
 * Copyright (C) 2010 Shinichiro Nakamura (CuBeatSystems)
 * http://shinta.main.jp/
 */
#include "mbed.h"
#include <string.h>

#ifndef _CONFIG_FILE_H_
#define _CONFIG_FILE_H_

/**
 * Configuration File class.
 */
class ConfigFile {
public:

    /**
     * Create a configuration file class.
     */
    ConfigFile();

    /**
     * Destroy a configuration file class.
     */
    ~ConfigFile();

    /**
     * Get a value for a key.
     *
     * @param key A target key name.
     * @param value A pointer to a value storage.
     * @param siz A size of a value storage.
     * @return A value or NULL.
     */
    bool getValue(char *key, char *value, size_t siz);

    /**
     * Set a set of a key and value.
     *
     * @param key A key.
     * @param value A value.
     *
     * @return True if it succeed.
     */
    bool setValue(char *key, char *value);

    /**
     * Remove a config.
     *
     * @param key A key.
     *
     * @return True if it succeed.
     */
    bool remove(char *key);

    /**
     * Remove all config.
     *
     * @return True if it succeed.
     */
    bool removeAll(void);

    /**
     * Get a number of configuration sets.
     *
     * @return number of configuration sets.
     */
    int getCount();

    /**
     * Get a key and a value.
     *
     * @param index Index number of this list.
     * @param key A pointer to a buffer for key.
     * @param keybufsiz A size of the key buffer.
     * @param value A pointer to a buffer for value.
     * @param valuebufsiz A size of the value buffer.
     *
     * @return true if it succeed.
     */
    bool getKeyAndValue(int index, char *key, size_t keybufsiz, char *value, size_t valuebufsiz);

    /**
     * Read from the target file.
     *
     * @param file A target file name.
     */
    bool read(char *file);

    typedef enum {
        UNIX,
        MAC,
        DOS
    } FileFormat;

    /**
     * Write from the target file.
     *
     * @param file A pointer to a file name.
     * @param header A pointer to a header.
     * @param ff File format.
     */
    bool write(char *file, char *header = NULL, FileFormat ff = UNIX);

private:
    typedef struct {
        char *key;
        char *value;
    } config_t;
    config_t **configlist;
    static const int MAXCONFIG = 64;
    static const int MAXLEN_KEY = 64;
    static const int MAXLEN_VALUE = 128;
    static const char SEPARATOR = '=';

    config_t *search(char *key);
    bool add(config_t *cfg);
};

#endif

