/**
 * Configuration file interface class (Version 0.0.1)
 *
 * Copyright (C) 2010 Shinichiro Nakamura (CuBeatSystems)
 * http://shinta.main.jp/
 */
#include "ConfigFile.h"

#define NEWLINE_UNIX "\n"
#define NEWLINE_DOS "\r\n"
#define NEWLINE_MAC "\r"

/**
 * Create a configuration file class.
 */
ConfigFile::ConfigFile() {
    /*
     * Allocation for a config_t list.
     */
    configlist = (config_t **)malloc(sizeof(config_t *) * MAXCONFIG);
    for (int i = 0; i < MAXCONFIG; i++) {
        configlist[i] = NULL;
    }
}

/**
 * Destroy a configuration file class.
 */
ConfigFile::~ConfigFile() {
    /*
     * Remove all storage and the contents.
     */
    for (int i = 0; i < MAXCONFIG; i++) {
        config_t *cfg = configlist[i];
        if (cfg != NULL) {
            free(cfg->key);
            free(cfg->value);
            free(cfg);
        }
        configlist[i] = NULL;
    }

    /*
     * Remove cnofig_t list.
     */
    free(configlist);
    configlist = NULL;
}

/**
 * Get a value for a key.
 *
 * @param key A target key name.
 * @param value A pointer to a value storage.
 * @param siz A size of a value storage.
 * @return A value or NULL.
 */
bool ConfigFile::getValue(char *key, char *value, size_t siz) {
    /*
     * Null check.
     */
    if (key == NULL) {
        return false;
    }

    /*
     * Search a config_t object from the key.
     */
    config_t *p = search(key);
    if (p == NULL) {
        return false;
    }

    /*
     * Check the storage size.
     */
    if (siz <= strlen(p->value)) {
        return false;
    }

    /*
     * Copy the value to the storage.
     */
    strcpy(value, p->value);
    return true;
}

/**
 * Set a set of a key and value.
 *
 * @param key A key.
 * @param value A value.
 *
 * @return True if it succeed.
 */
bool ConfigFile::setValue(char *key, char *value) {
    /*
     * Null check.
     */
    if ((key == NULL) || (value == NULL)) {
        return false;
    }

    /*
     * Size check.
     */
    if ((MAXLEN_KEY < strlen(key)) || (MAXLEN_VALUE < strlen(value))) {
        return false;
    }

    /*
     * Search a config_t object from the key.
     */
    config_t *p = search(key);
    if (p == NULL) {
        /*
         * Allocation a memory for a new key.
         */
        char *k = (char *)malloc(sizeof(char) * (strlen(key) + 1));
        if (k == NULL) {
            return false;
        }
        strcpy(k, key);

        /*
         * Allocation a memory for a new value.
         */
        char *v = (char *)malloc(sizeof(char) * (strlen(value) + 1));
        if (v == NULL) {
            free(k);
            return false;
        }
        strcpy(v, value);

        /*
         * Allocation a memory for a new configuration.
         */
        config_t *cfg = (config_t *)malloc(sizeof(config_t) * 1);
        if (cfg == NULL) {
            free(k);
            free(v);
            return false;
        }
        cfg->key = k;
        cfg->value = v;

        /*
         * Add the new configuration.
         */
        if (!add(cfg)) {
            free(k);
            free(v);
            free(cfg);
            return false;
        }

        return true;
    } else {
        /*
         * The value is same.
         */
        if (strcmp(value, p->value) == 0) {
            return true;
        }

        /*
         * Free a memory for the value.
         */
        free(p->value);
        p->value = NULL;

        /*
         * Allocation memory for the new value.
         */
        char *v = (char *)malloc(sizeof(char) * (strlen(value) + 1));
        if (v == NULL) {
            return false;
        }

        /*
         * Store it.
         */
        strcpy(v, value);
        p->value = v;

        return true;
    }
}

/**
 * Remove a config.
 *
 * @param key A key.
 *
 * @return True if it succeed.
 */
bool ConfigFile::remove(char *key) {
    if (key == NULL) {
        return false;
    }
    for (int i = 0; i < MAXCONFIG; i++) {
        config_t *cfg = configlist[i];
        if (cfg != NULL) {
            if (strcmp(cfg->key, key) == 0) {
                free(cfg->key);
                free(cfg->value);
                free(cfg);
                configlist[i] = NULL;
                return true;
            }
        }
    }
    return false;
}

/**
 * Remove all config.
 *
 * @return True if it succeed.
 */
bool ConfigFile::removeAll(void) {
    for (int i = 0; i < MAXCONFIG; i++) {
        config_t *p = configlist[i];
        if (p != NULL) {
            free(p->key);
            free(p->value);
        }
        free(p);
        configlist[i] = NULL;
    }
    return true;
}

/**
 * Get a number of configuration sets.
 *
 * @return number of configuration sets.
 */
int ConfigFile::getCount() {
    int cnt = 0;
    for (int i = 0; i < MAXCONFIG; i++) {
        config_t *p = configlist[i];
        if (p != NULL) {
            cnt++;
        }
    }
    return cnt;
}

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
bool ConfigFile::getKeyAndValue(int index, char *key, size_t keybufsiz, char *value, size_t valuebufsiz) {
    int cnt = 0;
    for (int i = 0; i < MAXCONFIG; i++) {
        config_t *p = configlist[i];
        if (p != NULL) {
            if (cnt == index) {
                if ((strlen(p->key) < keybufsiz) && (strlen(p->value) < valuebufsiz)) {
                    strcpy(key, p->key);
                    strcpy(value, p->value);
                    return true;
                }
                return false;
            }
            cnt++;
        }
    }
    return false;
}

/**
 * Read from the target file.
 *
 * @param file A target file name.
 */
bool ConfigFile::read(char *file) {
    /*
     * Open the target file.
     */
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        return false;
    }

    /*
     * Remove all configuration.
     */
    removeAll();

    /*
     * Read from a file.
     */
    char buf[MAXLEN_KEY + 8 + MAXLEN_VALUE];
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        /*
         * Ignore a comment.
         */
        if (buf[0] == '#') {
            continue;
        }

        /*
         * Trim a return.
         */
        const size_t len = strlen(buf);
        for (int i = 0; i < len; i++) {
            if ((buf[i] == '\r') || (buf[i] == '\n')) {
                buf[i] = '\0';
            }
        }

        /*
         * Separate key and value.
         */
        char k[MAXLEN_KEY];
        char v[MAXLEN_VALUE];
        char *sp = strchr(buf, SEPARATOR);
        if (sp != NULL) {
            strcpy(v, sp + 1);
            *sp = '\0';
            strcpy(k, buf);
            setValue(k, v);
        }
    }
    fclose(fp);
    return true;
}

/**
 * Write from the target file.
 *
 * @param file A pointer to a file name.
 * @param header A pointer to a header.
 * @param ff File format.
 */
bool ConfigFile::write(char *file, char *header, FileFormat ff) {
    /*
     * Open the target file.
     */
    FILE *fp = fopen(file, "w");
    if (fp == NULL) {
        return false;
    }

    /*
     * Set a type of new line.
     */
    char *newline = NEWLINE_UNIX;
    switch (ff) {
        case UNIX:
            newline = NEWLINE_UNIX;
            break;
        case MAC:
            newline = NEWLINE_MAC;
            break;
        case DOS:
            newline = NEWLINE_DOS;
            break;
        default:
            newline = NEWLINE_UNIX;
            break;
    }

    /*
     * Write the header.
     */
    if (header != NULL) {
        fprintf(fp, "%s%s", header, newline);
    }

    /*
     * Write the data.
     */
    for (int i = 0; i < MAXCONFIG; i++) {
        config_t *cfg = configlist[i];
        if (cfg != NULL) {
            fprintf(fp, "%s=%s%s", cfg->key, cfg->value, newline);
        }
    }
    fclose(fp);
    return true;
}

ConfigFile::config_t *ConfigFile::search(char *key) {
    if (key == NULL) {
        return NULL;
    }
    for (int i = 0; i < MAXCONFIG; i++) {
        if (configlist[i] != NULL) {
            if (strcmp(configlist[i]->key, key) == 0) {
                return configlist[i];
            }
        }
    }
    return NULL;
}

bool ConfigFile::add(config_t *cfg) {
    for (int i = 0; i < MAXCONFIG; i++) {
        if (configlist[i] == NULL) {
            configlist[i] = cfg;
            return true;
        }
    }
    return false;
}




