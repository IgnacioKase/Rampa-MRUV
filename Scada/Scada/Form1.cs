using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace Scada
{
    public partial class Form1 : Form
    {
        Formato inicializacionFormato = new Formato();
        List<ThemesAppearance> temas = new List<ThemesAppearance>();

        public Form1()
        {
            InitializeComponent();
            temas = inicializacionFormato.loadThemesFromXml();
            foreach (ThemesAppearance _x in temas)
            {
                if (_x.Name == "Dark")
                {
                    inicializacionFormato.inicioDesdeXml(Controls, this, _x);
                    toolStripComboBox1.Text = "Dark";
                }
                toolStripComboBox1.Items.Add(_x.Name);
            }
        }

        private void toolStripComboBox1_TextChanged(object sender, EventArgs e)
        {
            foreach (ThemesAppearance _x in temas)
            {
                if (_x.Name == toolStripComboBox1.Text)
                {
                    inicializacionFormato.inicioDesdeXml(Controls, this, _x);
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
        }
    }
}
