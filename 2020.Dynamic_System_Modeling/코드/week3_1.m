%%logical indexing 
vehicle = xlsread("../������/vehicle.xlsx");
vehicle(isnan(vehicle)) = 100 ;
vehicle

