# sdptk-iers-updater
Update leapsec and utcpole data files inside an SDPTK installation


## Requirements

* [SDP Toolkit](https://wiki.earthdata.nasa.gov/display/DAS/SDP+Toolkit+and+HDF-EOS+EOSDIS++Core+System+Project)
    * This must already be compiled and installed.
    * The _sdptk-iers-*_ tools must run as the user that owns at least the _database_ and _runtime_ directory trees.
* [Bash](https://www.gnu.org/software/bash/)
    * 4.2 or later
* [Curl](https://curl.haxx.se/)
    * 7.29 (ie, RHEL/Centos 7) is known to work
* Probably other GNU or Linux-centric utilities


## Setup

Choose a provided _*.inc_ file, or copy _settings.inc.template_ to a new file and edit the placeholders.

If using _cddis-https.inc_, or any other IERS data provider that requires [Earthdata Login](https://urs.earthdata.nasa.gov/), then add the _$HOME/.netrc_ file as described by [How To Access Data With cURL And Wget](https://wiki.earthdata.nasa.gov/display/EL/How+To+Access+Data+With+cURL+And+Wget).

For the tests below, preload the appropriate _$PGSHOME/bin/$BRAND/pgs-env.*_ file for your shell.

| Shell family | Example source command on 64-bit Linux |
| -- | -- |
| sh, ksh, bash, ... | `. /usr/local/sdptk/bin/linux64/pgs-env.ksh` |
| csh, tcsh, ... | `source /usr/local/sdptk/bin/linux64/pgs-env.csh` |


## A simple test

1. Download the latest IERS inputs to the appropriate database directories.

    ```
    sdptk-iers-fetch-inputs somesettings.inc
    ```

2. Run the updaters.

    ```
    sdptk-iers-run-updaters
    ```

3. Check the files.

    ```
    head $PGSHOME/database/common/TD/leapsec.dat $PGSHOME/database/common/CSC/utcpole.dat
    tail $PGSHOME/database/common/TD/leapsec.dat $PGSHOME/database/common/CSC/utcpole.dat
    ```


## TODO Use in a task scheduler

The IERS data files provided by CDDIS seem to be updated daily, but SDPTK can probably live with weekly updates.

`. /usr/local/sdptk/bin/linux64/pgs-env.ksh && sdptk-iers-fetch-inputs somesettings.inc && sdptk-iers-run-updaters`
