// See https://aka.ms/new-console-template for more information



Console.WriteLine("Enter a string for first List: ");
String names = Console.ReadLine();
var firstList = new List<string>();

//Apple Red Purple Pineapple Yellow Blue


string[] words = names.Split(' ');
foreach (var word in words)
{

    firstList.Add(word);
}

Console.WriteLine("\nAll Names in First list:\n");
foreach (var fruits in firstList)
{
    Console.WriteLine(fruits);
}
//Q(b)

Console.WriteLine("\nEnter a string for Second List: ");
String names2 = Console.ReadLine();
var secondList = new List<string>();

//Black Silver Mango

string[] words2 = names2.Split(' ');
foreach (var word in words2)
{

    secondList.Add(word);
}

Console.WriteLine("\nAll Names in Second list:\n");
foreach (var fruits in secondList)
{
    Console.WriteLine(fruits);
}
//Q(c)

secondList.InsertRange(0, firstList);
Console.WriteLine("\nAfter inserting First List on top of the second list :\n");

foreach (var fruits in secondList)
{
    Console.WriteLine(fruits);
}

//Q(d)
Console.WriteLine("\nAfter Discarding  names and keep color names: \n");
secondList.Remove("Apple");
secondList.Remove("Pineapple");
secondList.Remove("Mango");

foreach (var fruits in secondList)
{
    Console.WriteLine(fruits);
}

Console.WriteLine("\n");

//Q(e)
Console.WriteLine("\nAfter converting all the names of second list into Upper Case :\n");
foreach (var country in secondList)
{
    Console.Write(country.ToUpper() + "\n");
}
