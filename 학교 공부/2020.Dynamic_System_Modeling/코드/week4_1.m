%%plot 
gasprices = readtable("../������/gasprices.xlsx", "Range", "A5:K24");

Year = gasprices.Year;

Au = gasprices.Australia;
Ge = gasprices.Germany;
Me = gasprices.Mexico;
US = gasprices.USA;

avg = mean(Au(~isnan(Au))); %nan �� �ƴѰ͵��� ��� 
Au(isnan(Au)) = avg;

figure("Name","gasprices");

hold on ;   % �Ѱ��� ���ļ� ���ÿ� 
plot(Year,Au,'r--o')
plot(Year,Ge,'g--o')
% hold off  % ����
plot(Year,Me,'b--o')
title("Annual gas prices","Color","b")
xlabel("Year")
ylabel("Price")
legend("Au","Ge","ME")

xlim([1992,2006]); % ���� ���� 

figure("Name","gasprices subplot");
subplot(2,2,1)
plot(Year,Au,'r--o')
title("AU")
subplot(2,2,2)
plot(Year,Ge,'g--o')
title("GE")
subplot(2,2,3)
 plot(Year,Me,'b--o')
 title("ME")
 subplot(2,2,4)
 plot(Year,US,'b--o')
 title("US")
 % gird �� ��Ÿ���� y_scale �� ���� �ؾ��� 
 % ylim([1,8]) �� ����


[MaxPrice_USA,index] = max(US);























