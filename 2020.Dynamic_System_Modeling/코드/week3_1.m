%%logical indexing 
vehicle = xlsread("../ตฅภฬลอ/vehicle.xlsx");
vehicle(isnan(vehicle)) = 100 ;
vehicle

