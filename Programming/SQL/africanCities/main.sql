SELECT c.NAME
FROM CITY AS c
INNER JOIN (
      SELECT CODE, CONTINENT FROM COUNTRY
) AS country ON country.CODE = c.COUNTRYCODE
WHERE country.CONTINENT LIKE "Africa"
