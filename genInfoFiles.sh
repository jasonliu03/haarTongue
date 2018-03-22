ls -l posdata | awk -F ' ' '{print $9}' | grep -v '/' | grep -v '^$' > posdata.txt
sed -i "s/^/posdata\//g" posdata.txt
sed -i "s/$/ 1 0 0 20 20/g" posdata.txt

ls -l negdata | awk -F ' ' '{print $9}' | grep -v '/' | grep -v '^$' > negdata.txt
sed -i "s/^/negdata\//g" negdata.txt
