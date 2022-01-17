--Query 1
INSERT INTO CUSTOMER(Name, Phone)
VALUES		('D. Gia', '(972) 501-6784');

--Query 2
UPDATE	CUSTOMER
SET 	Phone = '(837) 721-8965'
WHERE	Name = 'D. Gia';

--Query 3
UPDATE	RATE 
SET 	Daily = Daily * 1.05
WHERE	Category = 1;

--Query 4a
INSERT INTO	VEHICLE(VehicleID, Description, Year, Type, Category)
VALUES		('5FNRL6H58KB133711', 'Honda Odyssey', 2019, 6, 1);

--Query 4b
INSERT INTO RATE(Type, Category, Weekly, Daily)
VALUES(5, 1, 900, 150), (6, 1, 800, 135);

--Query 5
SELECT 	V.VehicleID AS 'VIN', V.Description AS 'Description', V.Year AS 'Year', SUM(R.RentalType * R.Qty) AS 'TOTAL_DAYS'
FROM	VEHICLE AS V, RENTAL AS R
WHERE	V.Type = 1 AND V.Category = 1 
		AND (V.VehicleID, R.Qty, R.RentalType) IN ( SELECT	DISTINCT VehicleID, Qty, RentalType
							 						FROM	RENTAL 
							 						WHERE	(StartDate NOT BETWEEN '2019-06-01' AND '2019-06-20') 
															AND (ReturnDate NOT BETWEEN '2019-06-01' AND '2019-06-20')
															)
GROUP BY V.VehicleID;

--SUDO QUERY 5
SELECT 	V.VehicleID AS 'VIN', V.Description AS 'Description', V.Year AS 'Year', SUM(R.RentalType * R.Qty) AS 'TOTAL_DAYS'
FROM	VEHICLE AS V, RENTAL AS R
WHERE	V.Type = 1 AND V.Category = 1 
		AND (V.VehicleID, R.Qty, R.RentalType) IN ( SELECT	VehicleID, Qty, RentalType
							 						FROM	RENTAL 
							 						WHERE	(StartDate NOT BETWEEN '2019-06-01' AND '2019-06-20') 
															AND (ReturnDate NOT BETWEEN '2019-06-01' AND '2019-06-20')
															AND (StartDate > '2019-06-20' AND ReturnDate > StartDate)
															AND (ReturnDate < '2019-06-01' AND StartDate < ReturnDate) )
GROUP BY V.VehicleID;






--Query 6
SELECT C.Name, TotalAmount AS "Balance_Remaining"
FROM CUSTOMER AS C, RENTAL AS R
WHERE C.CustID = R.CustID AND C.CustID = 221 AND PaymentDate IS 'NULL';



--Query 7
SELECT	VehicleID AS "VIN", Description, Year,
    CASE	WHEN V.Type  = 1 THEN 'Compact'
        	WHEN V.Type  = 2 THEN 'Medium'
        	WHEN V.Type  = 3 THEN 'Large'
        	WHEN V.Type = 4 THEN 'SUV'
        	WHEN V.Type  = 5 THEN 'Truck'
        	WHEN V.Type = 6 THEN 'VAN'
    END AS Type,
    CASE	WHEN V.Category = 0 THEN 'Basic'
        	WHEN V.Category = 1 THEN 'Luxury'
    END AS Category,
    R.Daily,
    R.Weekly
FROM	VEHICLE AS V, RATE AS R
WHERE 	V.Type = R.Type AND V.Category = R.Category
ORDER BY V.Category DESC, V.Type DESC;


--Query 8	
SELECT	SUM(TotalAmount)
FROM	RENTAL
WHERE	ReturnDate <= CURRENT_DATE;

--Query 9a
SELECT DISTINCT V.VehicleID, Description, Year,
    CASE 
        WHEN V.Type  = 1 THEN 'Compact' 
        WHEN V.Type  = 2 THEN 'Medium' 
        WHEN V.Type  = 3 THEN 'Large' 
        WHEN V.Type = 4 THEN 'SUV' 
        WHEN V.Type  = 5 THEN 'Truck'
        WHEN V.Type = 6 THEN 'VAN' 
    END AS Type,
    CASE 
        WHEN V.Category = 0 THEN 'Basic' 
        WHEN V.Category = 1 THEN 'Luxury' 
    END AS Category,
    CASE 
        WHEN RentalType = 1 THEN 105 * Qty 
        WHEN RentalType = 7 THEN 600 * Qty 
    END AS Unit_Price,TotalAmount,
    CASE 
        WHEN RentalType = 1 THEN 105 * Qty - TotalAmount 
        WHEN RentalType = 7 THEN 600 * Qty - TotalAmount 
    END AS Payment,StartDate
FROM VEHICLE AS V, RENTAL AS R, RATE, CUSTOMER AS C
WHERE (V.VehicleID = R.VehicleID AND R.CustID = C.CustID AND C.Name="J. Brown")
ORDER BY StartDate ASC;

--Query 9b
SELECT SUM(R.TotalAmount) 
FROM RENTAL AS R, CUSTOMER AS C 
WHERE C.CustID = R.CustID AND R.PaymentDate = 'NULL' AND C.Name = "J. Brown";


--Query 10
SELECT	C.Name AS 'CUSTOMER_NAME', R.CustID AS 'CUSTOMER_ID', StartDate, ReturnDate, TotalAmount
FROM	CUSTOMER AS C, RENTAL AS R
WHERE	C.CustID = R.CustID AND R.VehicleID = '9VDE1F3XEE414842' AND R.RentalType = 7 AND R.PaymentDate IS 'NULL';


--Query 11
SELECT 	Name AS 'NAME', CUSTOMER.CustID AS 'CUSTOMER_ID'
FROM	CUSTOMER
WHERE	NOT EXISTS(	SELECT	R.CustID
					FROM	RENTAL AS R
					WHERE	R.CustID = CUSTOMER.CustID);

--Query 12
SELECT C.Name, V.Description, R.StartDate, R.ReturnDate, R.TotalAmount 
FROM VEHICLE AS V, RENTAL AS R, CUSTOMER AS C 
WHERE R.StartDate = R.PaymentDate AND C.CustID = R.CustID AND V.VehicleID = R.VehicleID 
ORDER BY C.Name;

