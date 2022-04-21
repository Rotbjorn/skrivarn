# skrivarn

C library used for logging in some of my other private projects. Heavily unfinished

To enable it in a build, `SKRIVARN_ENABLED` must be #defined


## Usage

```c
skrivarn_trace("This is a trace");
skrivarn_info("This is an info");
skrivarn_warn("This is a warning");
skrivarn_error("This is an error");
```

There is also a format variant available

```c
skrivarn_trace("This is a %s", "trace");
skrivarn_info("This is an %s", "info");
skrivarn_warn("This is a %s", "warn");
skrivarn_error("This is an %s", "error");
```


## TODO

- [ ] Header only?
- [ ] Runtime enable/disable