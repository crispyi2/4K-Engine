using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace _4K_Engine.Areas.Menu
{
    public class MenuController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
    }
}