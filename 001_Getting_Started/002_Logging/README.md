If you start a new project and want to copy the main.c only, in "sdkconfig" file, edit it some lines like that:

```bash
...
# CONFIG_LOG_DEFAULT_LEVEL_NONE is not set
# CONFIG_LOG_DEFAULT_LEVEL_ERROR is not set
# CONFIG_LOG_DEFAULT_LEVEL_WARN is not set
# CONFIG_LOG_DEFAULT_LEVEL_INFO is not set
# CONFIG_LOG_DEFAULT_LEVEL_DEBUG is not set
CONFIG_LOG_DEFAULT_LEVEL_VERBOSE=y
CONFIG_LOG_DEFAULT_LEVEL=5
...
```
This edit to use all verbosity levels.
