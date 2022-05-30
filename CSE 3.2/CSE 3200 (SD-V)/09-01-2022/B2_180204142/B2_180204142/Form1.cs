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
    public partial class Form1 : Form
    {
        public static string name, id;
        String actname = "Samit";
        String actid = "180204142";
        public Form1()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            name = textBox1.Text;
            id = textBox2.Text;

            if (name == actname && id == actid)
            {
                MessageBox.Show("Login Successful");
                this.Hide();
                Purchase f2 = new Purchase();
                this.Visible = false;
                f2.username = textBox1.Text;
                f2.password = textBox2.Text;
                f2.Show();
            }
            else
                MessageBox.Show("Incorrect name & password");
        }

        private void textBox2_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
