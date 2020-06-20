_cddis_iers_url='ftp://gdc.cddis.eosdis.nasa.gov/pub/products/iers'
url_to_tai_utc_dat=$_cddis_iers_url/tai-utc.dat
url_to_finals_data=$_cddis_iers_url/finals.data

extra_curl_options=(
    --ssl
)
