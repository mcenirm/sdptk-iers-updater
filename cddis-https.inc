_cddis_iers_url='https://cddis.nasa.gov/archive/products/iers'
url_to_tai_utc_dat=$_cddis_iers_url/tai-utc.dat
url_to_finals_data=$_cddis_iers_url/finals.data

_cookie_jar=$HOME/.edl_cookies
touch -- "$_cookie_jar"
extra_curl_options=(
    --netrc
    --cookie     "$_cookie_jar"
    --cookie-jar "$_cookie_jar"
    --location 
)
