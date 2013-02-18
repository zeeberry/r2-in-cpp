
#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class cpuschedule
{
	int n,servicetime[10], totalStime;
	float Totalwt,Averagewt,Wtime[10],AvgTT, TotalTT, throughput;
	
public:
	void Getdata();
	void RoundRobin();

};
//Getting user input
void cpuschedule::Getdata()
{
	int i;
	n = 5;
	totalStime = 0;
	cout<<"Number of processes: "<<n<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"Service Time for process "<<i<<"=	";
		cin>>servicetime[i];cout<<endl;
		totalStime = totalStime+servicetime[i];
	}
	cout<<"Total Service Time: "<<totalStime<<endl<<endl;
		
}



//Round Robin Algorithm
void cpuschedule::RoundRobin()
{

	int i,j,k,RRarraySize,tquantum,serviceT[10],Rrobin[10][10],count[10];
	int max=0;
	Totalwt=0.0;
	cout<<"Enter the Time Quantum= ";
	cin>>tquantum; cout<<endl;
	
	for(i=1;i<=n;i++)
	{
		serviceT[i]=servicetime[i];
		if(max<serviceT[i])
			max=serviceT[i];
		Wtime[i]=0;
	}

	//size of Rrobin array
	RRarraySize=max/tquantum+1;

	//initializing Rrobin array
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			Rrobin[i][j]=0;
		}
	}
	//populating Rrobin array
	i=1;
	while(i<=n)
	{
		j=1;
		while(serviceT[i]>0)
		{
			if(serviceT[i]>=tquantum)
			{
				serviceT[i]=serviceT[i]-tquantum;
				Rrobin[i][j]=tquantum;
				j++;
			}
			else
			{
				Rrobin[i][j]=serviceT[i];
				serviceT[i]=0;
				j++;
			}
		}
		count[i]=j-1;
		i++;
	}

	cout<<"Process Scheduling\n ";
	cout<<"\tP1 \tP2 \tP3 \tP4 \tP5\n";
    //outputting cycle for each process
   
	for(i=0;i<RRarraySize;i++)
	{    cout<<"Round"<<i+1<<"  ";            
		for(j=0;j<n;j++)
		{
			cout<<Rrobin[j+1][i+1];
			cout<<"\t";
		}
		cout<<endl;
		
	}
		cout<<endl;
	//calculating waiting time
	int x=1;
	i=1;
	while(x<=n)
	{
		for(int a=1;a<x;a++)
		{
			Wtime[x]=Wtime[x]+Rrobin[a][i];
		}
		i=1;
		int z=x;
		j=count[z];
		k=1;
		while(k<=j-1)
		{
			if(i==n+1)
			{
				i=1;
				k++;
			}
			else
			{
				if(i!=z)
				{
					Wtime[z]=Wtime[z]+Rrobin[i][k];
				}
				i++;
			}
		}
		x++;
	}
	for(i=1;i<=n;i++)
		cout<<"Waiting Time for process "<<i<<"= "<<Wtime[i]<<endl;;

	//Waiting Time 
	for(i=1;i<=n;i++)
		Totalwt=Totalwt+Wtime[i];
	Averagewt=Totalwt/n;
	cout<<"Total Waiting Time: "<<Totalwt<<endl;
	cout<<"Average Waiting Time: "<<Averagewt<<endl;
	
	//Turnaround Time
	TotalTT = Totalwt + totalStime;
	AvgTT= TotalTT/n;
	cout<<"Total Turnaround Time: "<<TotalTT<<endl;
	cout<<"Average Turnaround Time: "<<AvgTT<<endl;
	
	//Throughput1
	float tst = totalStime;
	float tstpn = (totalStime/tquantum);
	throughput = tstpn/n;
	cout<<"CPU Throughput: "<<throughput<<endl;
}//end RoundRobin


//MAIN CLASS
int main()
{
	cpuschedule cpu;
	int choice;
	
	cout<<"ROUND ROBIN SCHEDULING \n";
	cpu.Getdata();
	cpu.RoundRobin();
	
    cout<<"Exit? y/n ";
    cin>>choice;
    		
return 0;
}//end main
