using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace B2_180204142
{
    public partial class Purchase : Form
    {
        public static double unitprice1, unitprice2, unitprice3, unitprice4, unitprice5;
        public static int amount1, amount2, amount3, amount4, amount5;
        public double curCR;
        public string curType;
        public string username { get; set; }
        public string password { get; set; }
        public Purchase()
        {
            InitializeComponent();

            textBox11.ReadOnly = true;

            List<Currency> currency = new List<Currency>();
            currency.Add(new Currency() { conversionRate = 1.00, currencyType = "Taka" });
            currency.Add(new Currency() { conversionRate = 0.86, currencyType = "Rupee" });
            currency.Add(new Currency() { conversionRate = 0.012, currencyType = "US Dollar" });
            currency.Add(new Currency() { conversionRate = 0.015, currencyType = "Canadian Dollar" });
            currency.Add(new Currency() { conversionRate = 1.22, currencyType = "Japanese Yen" });

            comboBox1.DataSource = currency;
            comboBox1.DisplayMember = "currencyType";

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void label12_Click(object sender, EventArgs e)
        {

        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {
            unitprice3 = Convert.ToDouble(textBox7.Text);
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            unitprice2 = Convert.ToDouble(textBox5.Text);
        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {
            amount2 = Convert.ToInt32(textBox6.Text);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double totalPrice = unitprice1 * amount1 + unitprice2 * amount2 + unitprice3 * amount3 + unitprice4 * amount4 + unitprice5 * amount5;

            if (curType == "Taka")
            {
                textBox11.Text = Convert.ToString(totalPrice);
            }
            else if(curType == "Rupee")
            {
                textBox11.Text = Convert.ToString(totalPrice * curCR);
            }
            else if (curType == "US Dollar")
            {
                textBox11.Text = Convert.ToString(totalPrice * curCR);
            }
            else if (curType == "Canadian Dollar")
            {
                textBox11.Text = Convert.ToString(totalPrice * curCR);
            }
            else if (curType == "Japanese Yen")
            {
                textBox11.Text = Convert.ToString(totalPrice * curCR);
            }

        }

        private void textBox3_Leave(object sender, EventArgs e)
        {
            int box_int = 0;
            Int32.TryParse(textBox3.Text, out box_int);
            if (box_int < 0 && textBox3.Text != "")
            {
                textBox3.Text = "0";
                MessageBox.Show("Minimum allowed number is 0");
            }
            else if (box_int > 100 && textBox3.Text != "")
            {
                textBox3.Text = "100";
                MessageBox.Show("Maximum allowed number is 100");
            }
        }

        private void textBox1_TextChanged_1(object sender, EventArgs e)
        {
            unitprice4 = Convert.ToDouble(textBox1.Text);
        }

        private void textBox4_Leave(object sender, EventArgs e)
        {
            int box_int = 1;
            Int32.TryParse(textBox4.Text, out box_int);
            if (box_int < 1 && textBox4.Text != "")
            {
                textBox4.Text = "1";
                MessageBox.Show("Minimum allowed amount is 1");
            }
            else if (box_int > 10 && textBox4.Text != "")
            {
                textBox4.Text = "10";
                MessageBox.Show("Maximum allowed amount is 10");
            }
        }

        private void textBox5_Leave(object sender, EventArgs e)
        {
            int box_int = 0;
            Int32.TryParse(textBox5.Text, out box_int);
            if (box_int < 0 && textBox5.Text != "")
            {
                textBox5.Text = "0";
                MessageBox.Show("Minimum allowed number is 0");
            }
            else if (box_int > 100 && textBox5.Text != "")
            {
                textBox5.Text = "100";
                MessageBox.Show("Maximum allowed number is 100");
            }
        }

        private void textBox7_Leave(object sender, EventArgs e)
        {
            int box_int = 0;
            Int32.TryParse(textBox7.Text, out box_int);
            if (box_int < 0 && textBox7.Text != "")
            {
                textBox7.Text = "0";
                MessageBox.Show("Minimum allowed number is 0");
            }
            else if (box_int > 100 && textBox7.Text != "")
            {
                textBox7.Text = "100";
                MessageBox.Show("Maximum allowed number is 100");
            }
        }

        private void textBox1_Leave(object sender, EventArgs e)
        {
            int box_int = 0;
            Int32.TryParse(textBox1.Text, out box_int);
            if (box_int < 0 && textBox1.Text != "")
            {
                textBox1.Text = "0";
                MessageBox.Show("Minimum allowed number is 0");
            }
            else if (box_int > 100 && textBox1.Text != "")
            {
                textBox1.Text = "100";
                MessageBox.Show("Maximum allowed number is 100");
            }
        }

        private void textBox9_Leave(object sender, EventArgs e)
        {
            int box_int = 0;
            Int32.TryParse(textBox9.Text, out box_int);
            if (box_int < 0 && textBox9.Text != "")
            {
                textBox9.Text = "0";
                MessageBox.Show("Minimum allowed number is 0");
            }
            else if (box_int > 100 && textBox9.Text != "")
            {
                textBox9.Text = "100";
                MessageBox.Show("Maximum allowed number is 100");
            }
        }

        private void textBox6_Leave(object sender, EventArgs e)
        {
            int box_int = 1;
            Int32.TryParse(textBox6.Text, out box_int);
            if (box_int < 1 && textBox6.Text != "")
            {
                textBox6.Text = "1";
                MessageBox.Show("Minimum allowed amount is 1");
            }
            else if (box_int > 10 && textBox6.Text != "")
            {
                textBox6.Text = "10";
                MessageBox.Show("Maximum allowed amount is 10");
            }
        }

        private void textBox8_Leave(object sender, EventArgs e)
        {
            int box_int = 1;
            Int32.TryParse(textBox8.Text, out box_int);
            if (box_int < 1 && textBox8.Text != "")
            {
                textBox8.Text = "1";
                MessageBox.Show("Minimum allowed amount is 1");
            }
            else if (box_int > 10 && textBox8.Text != "")
            {
                textBox8.Text = "10";
                MessageBox.Show("Maximum allowed amount is 10");
            }
        }

        private void textBox2_Leave(object sender, EventArgs e)
        {
            int box_int = 1;
            Int32.TryParse(textBox2.Text, out box_int);
            if (box_int < 1 && textBox2.Text != "")
            {
                textBox2.Text = "1";
                MessageBox.Show("Minimum allowed amount is 1");
            }
            else if (box_int > 10 && textBox2.Text != "")
            {
                textBox2.Text = "10";
                MessageBox.Show("Maximum allowed amount is 10");
            }
        }

        private void textBox10_Leave(object sender, EventArgs e)
        {
            int box_int = 1;
            Int32.TryParse(textBox10.Text, out box_int);
            if (box_int < 1 && textBox10.Text != "")
            {
                textBox10.Text = "1";
                MessageBox.Show("Minimum allowed amount is 1");
            }
            else if (box_int > 10 && textBox10.Text != "")
            {
                textBox10.Text = "10";
                MessageBox.Show("Maximum allowed amount is 10");
            }
        }

        private void textBox9_TextChanged(object sender, EventArgs e)
        {
            unitprice5 = Convert.ToDouble(textBox9.Text);
        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {
            amount3 = Convert.ToInt32(textBox8.Text);
        }

        private void textBox2_TextChanged_1(object sender, EventArgs e)
        {
            amount4 = Convert.ToInt32(textBox2.Text);
        }

        private void textBox10_TextChanged(object sender, EventArgs e)
        {
            amount5 = Convert.ToInt32(textBox10.Text);
        }

        private void Purchase_Load(object sender, EventArgs e)
        {
            label15.Text = username;
            label16.Text = password;

            
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            amount1 = Convert.ToInt32(textBox4.Text);
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            Currency cur = comboBox1.SelectedItem as Currency;
            curCR = cur.conversionRate;
            curType = cur.currencyType;
         

            //textBox4.Text = Convert.ToString(cur.conversionRate);

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            unitprice1 = Convert.ToDouble(textBox3.Text);

            

        }
    }
}
