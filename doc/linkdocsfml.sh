#\bin\sh
find html -type f -exec sed -ie "s/.php.html/.php/g" {} \; -exec echo "Updated {}" \;
